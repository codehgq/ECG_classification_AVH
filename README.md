# ECG-classification
##  demo 简介
  - 构建基于心电的疾病分类模型，并部署到ARM-AVH虚拟硬件平台（例如硬件cortex-m55）
## 模型介绍
  - 基于心电数据进行疾病的分类，分类输出为7种。输入数据为10s的心电数据维数1x3600，输出维度为1x7。
   基于TensorFlow框架训练，模型结构为（CNN网络架构）,保存输出为pb格式。
##  部署流程
 ### 编译环境及配置
 ```bash
 cpackget add ARM.CMSIS.5.9.0.pack

 cpackget add ARM::CMSIS-DSP@1.15.0

cpackget add ARM::CMSIS-NN@4.1.0

cpackget add ARM::V2M_MPS3_SSE_300_BSP@1.4.0

cpackget add ARM::V2M_MPS3_SSE_310_BSP@1.3.0

cpackget add Keil::ARM_Compiler@1.7.2
 ```
执行命令配置cmsis
```bash
# download cmsis-toolbox
cmsis_toolbox_name="cmsis-toolbox-linux-amd64"
cmsis_toolbox_version="2.2.1"
cmsis_toolbox_url="https://github.com/Open-CMSIS-Pack/cmsis-toolbox/releases/download/${cmsis_toolbox_version}/${cmsis_toolbox_name}.tar.gz"
wget ${cmsis_toolbox_url}
tar -vxf ${cmsis_toolbox_name}.tar.gz
rm ${cmsis_toolbox_name}.tar.gz
 
# copy to opt
mv ${cmsis_toolbox_name} ctools
rm -rf /opt/ctools
mv ctools /opt
```
执行命令配置tvm和onnx 
 ```bash
echo 'export PATH=/home/ubuntu/.local/bin:$PATH' >> ~/.bashrc
source ~/.bashrc
pip install --upgrade pip
pip install opencv-python
pip install apache-tvm
pip install onnx
```
 ### 数据加载
    -- convert_ECGData.py
    -- convert_labels.py
 ### 模型转换
    模型转换为onnx
    ```bash
    python -m tf2onnx.convert --saved-model save/CNN --output  onnx/cnn_model.onnx
    ```
   模型转换为tvm
  ```bash TVM_TARGET="cortex-m55"
    sudo python3 -m tvm.driver.tvmc compile --target=cmsis-nn,c \
    --target-cmsis-nn-mcpu=$TVM_TARGET \
    --target-c-mcpu=$TVM_TARGET \
    --runtime=crt \
    --executor=aot \
    --executor-aot-interface-api=c \
    --executor-aot-unpacked-api=1 \
    --pass-config tir.usmp.enable=1 \
    --pass-config tir.usmp.algorithm=hill_climb \
    --pass-config tir.disable_storage_rewrite=1 \
    --pass-config tir.disable_vectorize=1 \
    cnn_model.onnx \
    --output-format=mlf \
    --model-format=onnx \
    --input-shapes x:[1,3600] \
    --module-name=cls \
    --output=cls.tar
  ```
 ### 模型编译
 ```bash
RUN_DEVICE_NAME="M55"
cbuild ECG_classification+PaddleClas$RUN_DEVICE_NAME.cprj
 ```
 ### 模型运行
 ```bash
VHT_Platform="FVP_Corstone_SSE-300"
$VHT_Platform  -C cpu0.CFGDTCMSZ=15 \
              -C cpu0.CFGITCMSZ=15 \
              -C mps3_board.uart0.out_file=\"-\" \
              -C mps3_board.uart0.shutdown_tag=\"EXITTHESIM\" \
              -C mps3_board.visualisation.disable-visualisation=1 \
              -C mps3_board.telnetterminal0.start_telnet=0 \
              -C mps3_board.telnetterminal1.start_telnet=0 \
              -C mps3_board.telnetterminal2.start_telnet=0 \
              -C mps3_board.telnetterminal5.start_telnet=0 \
              "out/ECG_classification/PaddleClas$RUN_DEVICE_NAME/ECG_classification.axf" \
              --stat
  ```
 ## 运行结果
标签为："A","B","L","N","R","V","|"分别表示为：
 - A：Atrial premature contraction 房性早搏，来自心房的早期心跳，比正常心跳提前出现
 - B：Left or right bundle branch block  左或右束支传导阻滞，表示心电图上可能出现左束支阻滞或右束支阻滞，具体需要通过波形分析确定是左侧还是右侧
 - L：Left bundle branch block beat 左束支传导阻滞，左心室的电信号传导受阻，通常显示在心电图上，心跳形态异常
 - N：Normal 正常的心跳
 - R：Right bundle branch block beat  右心室的电信号传导受阻，心电图上的心跳形态同样表现为异常
 - V：Premature ventricular contraction 室性早搏，来自心室的早期心跳，常见于正常人和心脏疾病患者
 - I：Isolated QRS-like artifact 孤立的QRS类似伪差，心电图上的伪差，看起来像是QRS波群，但实际上不是由正常的心电活动产生的
  <img width="417" alt="43b44fff8f9824fb4264d4b50172b0b" src="https://github.com/codehgq/ECG_classification_AVH/assets/39193613/5a00b987-9c81-4c65-bf08-d9c72eeac605">
  
## 参考

【1】[https://www.arm.com/products/development-tools/simulation/virtual-hardware] Virtual Hardware – Software Development Without Hardware – Arm®

【2】[http://share.recan-li.cn/iot-demo.html#1%E5%B5%8C%E5%85%A5%E5%BC%8F%E5%BC%80%E5%8F%91%E7%9A%84%E5%9F%BA%E6%9C%AC%E6%B5%81%E7%A8%8B] iot-demo

【3】[https://tvm.apache.org/docs/how_to/work_with_microtvm/micro_tvmc.html#tutorial-micro-cli-tool] 1. microTVM CLI Tool — tvm 0.17.dev0 documentation

【4】[https://github.com/ArmDeveloperEcosystem/Paddle-examples-for-AVH] Paddle-examples-for-AVH 

【5】[https://blog.csdn.net/heda3/article/details/] 博客链接

  

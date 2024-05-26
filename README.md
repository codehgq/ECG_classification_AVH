# ECG-classification
- demo 简介
  - 构建基于心电的疾病分类模型，并部署到ARM-AVH虚拟硬件平台（例如硬件cortex-m55）
- 模型介绍
  - 基于心电数据进行疾病的分类，分类输出为7种。输入数据为10s的心电数据维数1x3600，输出维度为1x7。
   基于TensorFlow框架训练，模型结构为（CNN网络架构）,保存输出为pb格式。
- 部署流程
  - 数据加载
    -- convert_ECGData.py
    -- convert_labels.py
  - 模型转换
    #### 模型转换为onnx
    '''
    python -m tf2onnx.convert --saved-model save/CNN --output  onnx/cnn_model.onnx
    '''
    #### 模型转换为tvm
    '''
    TVM_TARGET="cortex-m55"
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
    '''
  - 编译环境及配置
  - 模型编译
  - 模型运行

    ​
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

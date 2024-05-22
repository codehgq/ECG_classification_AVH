# windows 下运行的版本
import subprocess

command = 'python -m tf2onnx.convert --saved-model save/CNN --output  onnx/cnn_model.onnx'
# 执行一个简单的命令
result = subprocess.run(command, capture_output=True, text=True)

# 打印输出结果和错误信息（如果有）
print("输出:")
print(result.stdout)
print("错误:")
print(result.stderr)

# 检查命令是否成功执行
if result.returncode == 0:
    print("命令执行成功")
else:
    print("命令执行失败")


#python -m tf2onnx.convert --saved-model save/CNN --output  onnx/cnn_model.onnx

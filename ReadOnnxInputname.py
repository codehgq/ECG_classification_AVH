import onnx

# 加载 ONNX 模型
model_path = 'onnx/cnn_model.onnx'  # 替换为你的模型文件路径
model = onnx.load(model_path)

# 打印模型的输入节点名称
print("Input nodes of the model:")
for input in model.graph.input:
    print(input.name)

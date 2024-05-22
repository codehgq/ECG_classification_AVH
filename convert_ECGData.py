# Licensed to the Apache Software Foundation (ASF) under one
# or more contributor license agreements.  See the NOTICE file
# distributed with this work for additional information
# regarding copyright ownership.  The ASF licenses this file
# to you under the Apache License, Version 2.0 (the
# "License"); you may not use this file except in compliance
# with the License.  You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing,
# software distributed under the License is distributed on an
# "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
# KIND, either express or implied.  See the License for the
# specific language governing permissions and limitations
# under the License.

import pathlib
import sys
import numpy as np
import os
from sklearn import preprocessing
from sklearn.preprocessing import StandardScaler


def normalize_data(data, mean, std):
    shape = (1, 3600)
    mean = np.array(mean).reshape(shape).astype('float32')
    std = np.array(std).reshape(shape).astype('float32')
    norm_data = (data - mean) / std
    return norm_data.astype('float32')

def resize_norm_data(data):
    # 方式1
    ss = StandardScaler()
    shape = (1, 3600)
    ss.mean_ = np.loadtxt('trainData/train_mean_.txt', delimiter=' ')
    ss.scale_ = np.loadtxt('trainData/train_scale_.txt', delimiter=' ')
    ss.var_ = np.loadtxt('trainData/train_var_.txt', delimiter=' ')

    ss.mean_ = np.array(-0.19035).reshape(shape).astype('float32')
    ss.scale_ = np.array(2.8737).reshape(shape).astype('float32')
    ss.var_ = np.array(8.2582).reshape(shape).astype('float32')

    ss.n_features_in_ = 3600
    ss.n_samples_seen_ = 19

    std_data = ss.fit_transform(data)

    return std_data


def create_header_file(name, tensor_name, tensor_data, output_path):
    """
    This function generates a header file containing the data from the numpy array provided.
    """
    file_path = pathlib.Path(f"{output_path}/" + name).resolve()
    # Create header file with npy_data as a C array
    raw_path = file_path.with_suffix(".h").resolve()
    with open(raw_path, "w+") as header_file:
        header_file.write(
            "\n"
            + f"const size_t {tensor_name}_len = {tensor_data.size};\n"
            + f'__attribute__((section(".data.tvm"), aligned(16))) float {tensor_name}[] = '
        )

        header_file.write("{")
        for i in np.ndindex(tensor_data.shape):
            header_file.write(f"{tensor_data[i]}, ")
        header_file.write("};\n\n")


def create_headers(file_path):
    """
    This function generates C header files for the input and output arrays required to run inferences
    """
    # Create input header file
    # Resize image to 32x320
    # img = cv2.imread(img_path)
    # img = resize_norm_img(img)
    # img_data = img.astype("float32")
    # # Add the batch dimension, as we are expecting 4-dimensional input: NCHW.
    # img_data = np.expand_dims(img_data, axis=0)
    #读取数据
    try:
        X = np.loadtxt(file_path, delimiter=',', encoding='utf-8').astype('float32')  # [choose_index]
        # X = pd.read_csv(file_path, encoding='utf-8').astype('float32')
        print("Data loaded successfully:")
    except Exception as e:
        print(f"Failed to load data: {e}")
    #标准化数据

    ss = StandardScaler()
    # meanvalue = -0.19035727173611108
    # scalevalue = 2.873714299155556
    # varvalue = 8.258235232672222
    # ss.mean_ = np.full((1, 3600), meanvalue, dtype='float32')
    # ss.scale_ = np.full((1, 3600), scalevalue, dtype='float32')
    # ss.var_ = np.full((1, 3600), varvalue, dtype='float32')
    # 加载数据
    ss.mean_ = np.loadtxt('trainData/train_mean_.txt', delimiter=' ')
    ss.scale_ = np.loadtxt('trainData/train_scale_.txt', delimiter=' ')
    ss.var_ = np.loadtxt('trainData/train_var_.txt', delimiter=' ')

    ss.n_features_in_ = 3600
    ss.n_samples_seen_ = 1
    # 常用于将一维数组转换为单行的二维数组
    X_reshaped = X.reshape(1, -1)

    std_data = ss.transform(X_reshaped)
    #扩展维度
    X_std_data = np.expand_dims(std_data, axis=2)

    # Create input header file
    create_header_file("inputs", "input", X_std_data, "include")
    # Create output header file
    output_data = np.zeros([7], np.float32)
    create_header_file("outputs", "output", output_data, "include")


if __name__ == "__main__":
    # path = 'data/TestX_eu_MLIII.csv'
    # create_headers(path)
    create_headers(sys.argv[1])


#linux  python3 ./convert_image.py ./data/TestX_eu_MLIII.csv
#windows  python3 convert_image.py   data/TestX_eu_MLIII.csv
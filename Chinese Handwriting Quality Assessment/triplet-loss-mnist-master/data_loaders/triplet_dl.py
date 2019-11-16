# -- coding: utf-8 --
"""
Copyright (c) 2018. All rights reserved.
Created by C. L. Wang on 2018/4/18
"""
from keras.datasets import mnist
from keras.utils import to_categorical
from keras.preprocessing.image import img_to_array
from sklearn.model_selection import train_test_split
from imutils import paths
import numpy as np
import random
import cv2
import os

from bases.data_loader_base import DataLoaderBase


class TripletDL(DataLoaderBase):
    def __init__(self, config=None):
        # Initialize data and labels
        data = []
        labels = []

        super(TripletDL, self).__init__(config)
        # (self.X_train, self.y_train), (self.X_test, self.y_test) = mnist.load_data_local()
        imagePaths = "/Users/wangyoujia/Desktop/image-classification-keras/images_2"
        imagePaths = sorted(list(paths.list_images(imagePaths)))
        random.seed(42)
        random.shuffle(imagePaths)

        for imagePath in imagePaths:
            # load the image, pre-process it, and store it in the data list
            image = cv2.imread(imagePath)
            image = cv2.resize(image, (64, 64))
            image = img_to_array(image)
            data.append(image)

            label = imagePath.split(os.path.sep)[-2]
            label = 1 if label == "center" else 0
            labels.append(label)

        data = np.array(data, dtype="float") / 255.0
        labels = np.array(labels)

        # 展平数据，for RNN，感知机
        # self.X_train = self.X_train.reshape((-1, 28 * 28))
        # self.X_test = self.X_test.reshape((-1, 28 * 28))

        # 图片数据，for CNN
        # self.X_train = self.X_train.reshape(self.X_train.shape[0], 28, 28, 1)
        # self.X_test = self.X_test.reshape(self.X_test.shape[0], 28, 28, 1)
        #
        # self.y_train = to_categorical(self.y_train)
        # self.y_test = to_categorical(self.y_test)
        (self.X_train, self.X_test, self.y_train, self.y_test) = train_test_split(data,
                labels, test_size=0.25, random_state=42)

        # tries code
        # self.X_train = self.X_train.reshape(self.X_train.shape[0], 28, 28, 1)
        # self.X_test = self.X_test.reshape(self.X_test.shape[0], 28, 28, 1) (failed)
        # self.X_train = self.X_train.reshape((-1, 28 * 28))
        # self.X_test = self.X_test.reshape((-1, 28 * 28)) (failed)

        # 将标签从整数转换成向量，使用one-hot编码
        self.y_train = to_categorical(self.y_train, num_classes=2)
        self.y_test = to_categorical(self.y_test, num_classes=2)

        print("[INFO] X_train.shape: %s, y_train.shape: %s"
              % (str(self.X_train.shape), str(self.y_train.shape)))
        print("[INFO] X_test.shape: %s, y_test.shape: %s"
              % (str(self.X_test.shape), str(self.y_test.shape)))

    def get_train_data(self):
        return self.X_train, self.y_train

    def get_test_data(self):
        return self.X_test, self.y_test

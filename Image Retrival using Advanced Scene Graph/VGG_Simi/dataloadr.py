import os
import torch
import pandas as pd
from skimage import io, transform
import numpy as np
import matplotlib.pyplot as plt
from torch.utils.data import Dataset, DataLoader
from torchvision import transforms, utils
from  PIL import Image

def generate_filenames(root_dir):
    filenames = os.listdir(root_dir)

    return filenames


class ImageLoder(Dataset):
    def __init__(self,root_dir,transform=None):
        self.filename = generate_filenames(root_dir)
        self.root_dir = root_dir
        self.transform = transform


    def __len__(self):
        return  len(self.filename)


    def __getitem__(self, idx):
        abs_img = os.path.join(self.root_dir,self.filename[idx])
        image = Image.open(abs_img)
        image = image.convert('RGB')
        image = image.resize((32,32),Image.ANTIALIAS)
        if self.transform:
            image = self.transform(image)
        return image,abs_img


def get_dataloader(root_dir,batch_size,num_works=4):
    transformer = transforms.Compose([transforms.Resize(32),transforms.ToTensor()])
    transformed_dsets = ImageLoder(root_dir=root_dir,transform=transformer)
    d = DataLoader(transformed_dsets, batch_size=batch_size,num_workers=num_works)
    return d



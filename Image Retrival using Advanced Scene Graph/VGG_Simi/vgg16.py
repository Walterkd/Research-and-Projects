

import torch
import torch.nn as nn
import torchvision
import torchvision.transforms as transforms


cfgs = {'vgg19':[64,64,'POOL',128,128,'POOL',256,256,256,'POOL',512,512,512,512,'POOL',512,512,512,512,'POOL'],
        'vgg16': [64, 64, 'POOL', 128, 128, 'POOL', 256, 256, 256, 'POOL', 512, 512, 512, 'POOL', 512, 512, 512, 'POOL'],
        }



def _make_layers(cfg, in_channels, batch_norm=False):
    layers = []
    for v in cfg:
        if v == 'POOL':
            layers += [nn.MaxPool2d(kernel_size=2,stride=2)]
        else:
            conv2d = nn.Conv2d(in_channels, v, kernel_size=3,padding=1)
            if batch_norm:
                layers += [conv2d,nn.BatchNorm2d(v),nn.ReLU(inplace=1)]
            else:
                layers += [conv2d, nn.ReLU(inplace=1)]

            in_channels = v


    return nn.Sequential(*layers)

class VGG(nn.Module):
    def __init__(self, features, num_classes, init_weights=False):
        super(VGG,self).__init__()
        self.features = features
        self.avgpool = nn.AdaptiveAvgPool2d((7,7))

        self.fc1 = nn.Linear(512 * 7 * 7, 4096)
        self.relu = nn.ReLU()
        self.drop = nn.Dropout()
        self.fc2 = nn.Linear(4096, 512)
        self.fc3 = nn.Linear(512, num_classes)

        if init_weights:
            #TODO
            pass


    def forward(self, x):
        x = self.features(x)
        x = self.avgpool(x)
        x= x.view(-1,512*7*7)
        x = self.fc1(x)
        x = self.relu(x)
        x = self.drop(x)
        x = self.fc2(x)
        x = self.relu(x)
        x = self.drop(x)

        self.extract_features = x

        x = self.fc3(x)

        return  x



def _vgg(arch, cfg,batch_norm, pretrained,progress,**kwargs):
    if pretrained:
        #TODO
        pass

    print('Generate model {} '.format(arch))
    in_channels = kwargs['in_channels']
    num_classes = kwargs['num_classes']
    model = VGG(features=_make_layers(cfg=cfgs[cfg],
                                      in_channels=in_channels,
                                      batch_norm=batch_norm),
                num_classes=num_classes)

    if pretrained:
        pass
        #TODO


    return  model




#=====================================================================================================

def vgg16(pretrained=False, progress=False,**kwargs):
    return  _vgg('VGG16','vgg16',1,0,0,**kwargs)


num_epochs = 500#10
num_classes = 10
batch_size = 64#100
learning_rate = 0.001
print("Initializing Datasets and Dataloaders...")

# CIFIAR100 dataset
train_dataset = torchvision.datasets.CIFAR10(root='../data/',
                                           train=True,
                                           transform=transforms.ToTensor(),
                                           download=True)

test_dataset = torchvision.datasets.CIFAR10(root='../data/',
                                          train=False,
                                          transform=transforms.ToTensor())

# Data loader
train_loader = torch.utils.data.DataLoader(dataset=train_dataset,
                                           batch_size=batch_size,
                                           shuffle=True)

test_loader = torch.utils.data.DataLoader(dataset=test_dataset,
                                          batch_size=batch_size,
                                            shuffle=False)

def train():

	device = torch.device('cuda:0' if torch.cuda.is_available() else 'cpu')

	model = vgg16(in_channels=3,num_classes=num_classes)
	model = model.to(device)

	criterion = nn.CrossEntropyLoss()
	optimizer = torch.optim.Adam(model.parameters(),lr=learning_rate)


	total_step = len(train_loader)
	for epoch in range(num_epochs):
	    for i,(images,labels) in enumerate(train_loader):
	        images = images.to(device)
	        labels = labels.to(device)

	        outputs = model(images)
	        loss = criterion(outputs,labels)

	        optimizer.zero_grad()
	        loss.backward()
	        optimizer.step()

	        if (i + 1) % 100 == 0:
	            print('Epoch [{}/{}], Step [{}/{}], Loss: {:.4f}'
	                  .format(epoch + 1, num_epochs, i + 1, total_step, loss.item()))


	model.eval()
	with torch.no_grad():
	    correct = 0
	    total = 0
	    for images,labels in test_loader:
	        images = images.to(device)
	        labels = labels.to(device)

	        outputs = model(images)
	        _,pred = torch.max(outputs,1)
	        total += labels.size(0)
	        correct += (pred==labels).sum().item()

	    print('Test Accuracy of the model on the 10000 test images: {} %'.format(100 * correct / total))


	#save model
	torch.save(model.state_dict(),'./model/vgg16.model')
	print('train finished! model saved')


if __name__ == '__main__':
	train()

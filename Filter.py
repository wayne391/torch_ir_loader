import torch
import torch.nn as nn
from torch.nn import functional as F


class ConvFIR(nn.Module):
    def __init__(self, h, is_flip=True):
        super(ConvFIR, self).__init__()
        """
        Temporal domain FIR layer
        h (tensor or np array): transfer function, shape: (n_samples,)
        """
    
        # convert np to torch
        if type(h) == np.ndarray:
            h = torch.from_numpy(h).float()
        
        # init
        self.h = h
        self.len_h = len(h)
        self.conv = nn.Conv1d(1, 1, self.len_h, bias=False)
    
        # flip kernel
        if is_flip:
            h = torch.flip(h, dims=(0,))
            
        # load IR
        with torch.no_grad():
            self.conv.weight.copy_(h).float()

    def forward(self, x):
        x = self.conv(x)
        return x

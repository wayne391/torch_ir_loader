import torch
from Filter import ConvFIR

# load test file
path_x = 'DI_Test.wav'
y, sr = sf.read(path_x)
print(sr, y.shape)

# load impulse response
path_ir = 'IR.wav'
h, sr = sf.read(path_ir)
h = h[:2048]
print(sr, h.shape)

librosa.display.waveplot(h, sr)

# ---------
# use `scipy.signal.fftconvolve`
y_conv_fft = fftconvolve(y, h, mode='valid')

# use `np.convolve`
y_conv_np = np.convolve(y, h, mode='valid')
print('Difference (np.convolve v.s. scipy.signal.fftconvolve):', np.sum(np.abs(y_conv_np - y_conv_fft)))

# use torch
conv_torch = ConvFIR(h)
y_intensor = torch.from_numpy(y).float().unsqueeze(0).unsqueeze(0)
y_outtensor = conv_torch(y_intensor)
y_conv_torch = y_outtensor.squeeze().detach().numpy()
print('Difference     (pytorch v.s. scipy.signal.fftconvolve):', np.sum(np.abs(y_conv_torch - y_conv_fft)))
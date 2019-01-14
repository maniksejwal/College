clc;
b = 0;
fc = .05;
delta = .05;
n = (0:0.3:20);
x = sin(2*pi*fc*n);
y = zeros(size(x));

for i=1:length(n)
    e=x(i)-b;
    t=sign(e);
    if t==1
        y(1+i) = x(i)+delta;
        b=y(i+1);
    else
        y(i+1) = x(i)-delta;
        b=y(i+1);
    end
end

fftx = fft(x);
ffty = fft(y);
figure(1);
title("Fourier transform");
plot(fftshift(abs(fftx)),'b');
hold on;
plot(fftshift(abs(ffty)),'r');
figure(2);
title("Analogue wave staircase");
plot(n,x,'b');
hold on;
n1=[0 n];
stairs(n1,y,'r');
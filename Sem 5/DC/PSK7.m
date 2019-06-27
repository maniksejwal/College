clc
close all
tb = 1;
fc = 1/tb;
b = [1 0 0 1 0 1 1 0 1 1];
n = length(b);
t = 0:0.001:9.9999;
car = sqrt(2)*sin(2*pi*fc*t);
psk = zeros(1000*n);

for i = 1:n
    if b(i) == 1
        psk(1000*i-999 : 1000*i) = car(1000*i-999 : 1000*i);
    else
        psk(1000*i-999 : 1000*i) = -car(1000*i-999 : 1000*i);
    end
end

figure(1);
subplot(311);
stairs(0:10, [b b(10)], 'black', 'linewidth', 1);
axis([0, 10, -0.2, 1.2]);
xlabel('time'); ylabel('amplitude'); title('message bits');

subplot(312);
plot(t, car, 'black', 'linewidth', 1);
xlabel('time'); ylabel('amplitude'); title('carrier signal');

subplot(313);
plot(0:0.001:9.999, psk, 'black', 'linewidth', 1);
xlabel('time'); ylabel('amplitude'); title('PSK modulated signal');

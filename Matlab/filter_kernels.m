%% 450 Hz low-pass filter kernel %%

clear all;
close all;
clc;

fc1 = 450;  % cutoff frequency
fs1 = 1000; % sampling frequency
h1 = fir1(100,fc1/fs1, "low");

csvwrite("450hz_LPF_kernal.txt", h1); % save filter kernel to csv

%% 25 Hz high-pass filter kernel %%


fc2 = 25;  % cutoff frequency
fs2 = 1000; % sampling frequency
h2 = fir1(100,fc2/fs2, "high");

csvwrite("25hz_HPF_kernal.txt", h2); % save filter kernel to csv


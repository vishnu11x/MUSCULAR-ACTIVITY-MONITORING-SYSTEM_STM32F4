clear all;
close all;
clc;

%% 450 Hz low-pass filter kernel %%


fc2 = 25;  % cutoff frequency
fc1 = 450;  % cutoff frequency
fs1 = 1000; % sampling frequency
h1 = fir1(30,fc1/fs1, "low");

csvwrite("450hz_LPF_kernal.txt", h1); % save filter kernel to csv

%% 25 Hz high-pass filter kernel %%


fc2 = 25;  % cutoff frequency
fs2 = 1000; % sampling frequency
h2 = fir1(30,fc2/fs2, "high");

csvwrite("25hz_HPF_kernal.txt", h2); % save filter kernel to csv

%% bandpass filter %%
% Define filter parameters
fs = 1000; % Sampling frequency in Hz
f_low = 25; % Lower cutoff frequency in Hz
f_high = 450; % Upper cutoff frequency in Hz
N = 30; % Filter order

% Normalize cutoff frequencies
normalized_low_freq = f_low / (fs/2);
normalized_high_freq = f_high / (fs/2);

% Design FIR bandpass filter kernel
b = fir1(N, [normalized_low_freq, normalized_high_freq], 'bandpass');

csvwrite("bandpass.txt", b); % save filter kernel to csv


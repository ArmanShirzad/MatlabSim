% consunsus of linear multi-agent system simulation

clc
close all
clear all


% Linear system
A = [1 0;1 2];
B=[1;1]
% initial conditions
x10 = [0.3 -0.3];
x20 = [-0.2 0 ];
x30 = [-0.2 0.2 ];
x40 = [0 0.1 ];
x50 = [0.2 0];


% number of states
n = length(A);
% Laplacian matrix
L = [3 -1 -1 0 -1;
    -1 2 -1 0 0;
    -1 -1 3 -1 0;
    0 0 -1 2 -1;
    -1 0 0 -1 2];

% number of agents
N = length(L);

% feedback gains c and K
c=1;
% Pole placement
K=-place(A,B,[-2 -3]);

% obtained closed loop eigenvalues
eig(A+c*B*K)

% Run simulink file
sim('simconsensusbasic')

module JKtestBench;

parameter CYCLE = 20;
reg clk,j,k;
wire q;

JKFF mut(q,j,k,clk);

always #

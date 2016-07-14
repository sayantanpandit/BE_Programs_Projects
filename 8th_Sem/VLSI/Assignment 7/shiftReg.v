module shiftReg (clk, enable, serialIn, serialOut); 
input clk,serialIn,enable; 
output serialOut; 
reg [7:0] data; 
 
  always @(negedge clk) 
    begin 
      if (enable) 
        begin 
          data = data << 1; 
          data[0] = serialIn; 
        end 
    end 
    assign serialOut  = data[7]; 
endmodule 

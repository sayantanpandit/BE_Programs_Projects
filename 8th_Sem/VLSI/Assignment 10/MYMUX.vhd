----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    13:12:22 03/28/2016 
-- Design Name: 
-- Module Name:    MYMUX - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

---- Uncomment the following library declaration if instantiating
---- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity MYMUX is
    Port ( IN0 : in  STD_LOGIC;
           IN1 : in  STD_LOGIC;
           IN2 : in  STD_LOGIC;
           IN3 : in  STD_LOGIC;
           IN4 : in  STD_LOGIC;
           IN5 : in  STD_LOGIC;
           IN6 : in  STD_LOGIC;
           IN7 : in  STD_LOGIC;
           S2 : in  STD_LOGIC;
           S1 : in  STD_LOGIC;
           S0 : in  STD_LOGIC;
           MUX_OUT : out  STD_LOGIC);
end MYMUX;

architecture Behavioral of MYMUX is
	begin
		mux:process(S0,S1,s2,IN0,IN1,IN2,IN3,IN4,IN5,IN6,IN7)--here we give the process a label"mux"
		begin
		--Here we are going to use if-else statements
			if(S0='0' and S1='0' and s2='0')then
				MUX_OUT<=IN0;
			elsif(S0='1' and S1='0' and s2='0')then
    				MUX_OUT<=IN1;
			elsif(S0='0' and S1='1' and s2='0')then
				MUX_OUT<=IN2;
			elsif(S0='1' and S1='1' and s2='0')then
				MUX_OUT<=IN3;
			elsif(S0='0' and S1='0' and s2='1')then
			   MUX_OUT<=IN4;
			elsif(S0='1' and S1='0' and s2='1')then
			   MUX_OUT<=IN5;
			elsif(S0='0' and S1='1' and s2='1')then
			   MUX_OUT<=IN6;
			elsif(S0='1' and S1='1' and s2='1')then
			   MUX_OUT<=IN7;
			else 
				MUX_OUT<='X';--forcing unknown
		end if;
	end process;
end Behavioral;


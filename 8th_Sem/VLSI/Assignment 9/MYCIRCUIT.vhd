----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    15:08:08 04/05/2016 
-- Design Name: 
-- Module Name:    MYCIRCUIT - STRUCTURAL 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision ZERO.ZEROONE - File Created
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

entity MYCIRCUIT is
    Port ( I1 : in  STD_LOGIC;
           I2 : in  STD_LOGIC;
           I3 : in  STD_LOGIC;
           I4 : in  STD_LOGIC;
           I5 : in  STD_LOGIC;
           O1 : out  STD_LOGIC;
           O2 : out  STD_LOGIC);
end MYCIRCUIT;
architecture STRUCTURAL of MYCIRCUIT is
component MYMUX is
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
end component;
signal I4BAR,ONE,ZERO: STD_LOGIC;
begin
I4BAR<= not(I4);
ONE<='1';
ZERO<='0';
	MYMUX1: MYMUX
	        PORT MAP(IN0=>ONE,IN1=>ONE,IN2=>ONE,IN3=>ONE,IN4=>ONE,IN5=>ZERO,IN6=>ONE,IN7=>I4BAR,S2=>I1,S1=>I2,S0=>I3,MUX_OUT=>O1);
   MYMUX2: MYMUX
	         PORT MAP(IN0=>I5,IN1=>I5,IN2=>I5,IN3=>ZERO,IN4=>ONE,IN5=>ONE,IN6=>ONE,IN7=>ZERO,S2=>I2,S1=>I3,S0=>I4,MUX_OUT=>O2);
end STRUCTURAL;


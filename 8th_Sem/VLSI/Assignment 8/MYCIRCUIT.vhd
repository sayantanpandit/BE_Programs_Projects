----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    10:50:06 03/31/2016 
-- Design Name: 
-- Module Name:    MYCIRCUIT - Behavioral 
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

entity MYCIRCUIT is
    Port ( W : in  STD_LOGIC;
           X : in  STD_LOGIC;
           Y : in  STD_LOGIC;
           Z : in  STD_LOGIC;
           OUTPUT : out  STD_LOGIC);
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
signal NOTZ: STD_LOGIC;
begin
NOTZ<= not (Z);
	   MYMUX1: MYMUX
			     port map(NOTZ,Z,Z,NOTZ,Z,NOTZ,NOTZ,Z,W,X,Y,OUTPUT);
end STRUCTURAL;


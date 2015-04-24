{{ Pin Tester

Tests for electrical connection between any P0..29 and any other P0..29
Tests P30..31 by using serial output on those pins at 115200 baud

}}

CON
  _clkmode = xtal1 + pll16x
  _xinfreq = 5_000_000
  _stack = ($3000 + $3000 + 100) >> 2   'accomodate display memory and stack

PUB Start | p, mask

  mask := !(|<29 | |<28 | |<31 | |<30)
  dira |= mask
  outa := 0

  waitcnt(clkfreq*1+cnt)

  repeat
    repeat p from 0 to 27
      outa[p] := 1
      waitcnt(clkfreq/4+cnt)
      outa[p] := 0


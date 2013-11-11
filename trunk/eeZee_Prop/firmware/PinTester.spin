{{ Pin Tester

Tests for electrical connection between any P0..29 and any other P0..29
Tests P30..31 by using serial output on those pins at 115200 baud

}}

CON
  _clkmode = xtal1 + pll16x
  _xinfreq = 5_000_000
  _stack = ($3000 + $3000 + 100) >> 2   'accomodate display memory and stack

OBJ
  pc : "FullDuplexSerial"
  
PUB Start | p, mask

  waitcnt(clkfreq*5 + cnt)
  pc.Start(31, 30, 0, 115200)

  mask := !(|<31 | |<30)
  dira |= mask

  repeat
    waitcnt(clkfreq + cnt)
    pc.tx(10)
    pc.tx(13)
    pc.tx(10)
    pc.tx(13)
    pc.tx(10)
    pc.tx(13)
    pc.str(String("Pin Tester Starting"))
    repeat 3
      pc.tx(".")
      waitcnt(clkfreq + cnt)
    pc.tx(10)
    pc.tx(13)
     
  ' We can test pins 0..29 easily enough
  ' Pin 28, 29 are pulled up for I2C
  ' Pin 30, 31 are for serial, however
  
    repeat p from 0 to 30
      testPin(p, false, mask)      
      waitcnt(clkfreq+cnt)
{{
    repeat p from 0 to 30
      testPin(p, true, mask)      
      waitcnt(clkfreq/100+cnt)
}}
    pc.str(String("All Done"))
    pc.tx(10)
    pc.tx(13)

PUB testPin(pin, inverse, mask) | out, state
{{
Tests a pin out of the set of prop pins. Can either test inverse (all pins high except pin) or standard
(set pin high, others low). Mask specifies which pins to ignore setting/checking. Expects dira to be set
Leaves outa in the test state after return
}}
    out := (|< pin)
    if inverse
      out := !out
    out &= mask
    outa := out
    state := (ina & mask)

    pc.dec( pin )
    pc.tx(" ")
    pc.bin( out, 28 )
    pc.tx(" ")
    pc.bin( state, 28 )
    pc.tx(" ")
    pc.str(String("...."))
    if state <> out
      pc.str(String("FAIL"))
    else
      pc.str(String("ok"))
    pc.tx(10)
    pc.tx(13)


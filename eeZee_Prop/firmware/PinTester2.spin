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

  pc.Start(31, 30, 0, 115200)

  mask := !(|<31 | |<30 | |<29 | |<28)

  repeat
    waitcnt(clkfreq + cnt)
    pc.tx(13)
    pc.tx(13)
    pc.tx(13)
    pc.str(String("Pin Tester Starting"))
    repeat 3
      pc.tx(".")
      waitcnt(clkfreq + cnt)
    pc.tx(13)

  ' Assume P0-P15 connected and P16-P31 connected
  ' So we can test to be sure there's output/input
  ' Pin 28, 29 are pulled up for I2C
  ' Pin 30, 31 are for serial, however

    testPin(0, 1, mask)
    waitcnt(clkfreq/10+cnt)
    
    repeat p from 1 to 15
      testPin(p, 0, mask)      
      waitcnt(clkfreq/10+cnt)

    waitcnt(clkfreq*5+cnt)

    testPin(16, 17, mask)
    waitcnt(clkfreq/10+cnt)

    repeat p from 17 to 27
      testPin(p, 16, mask)
      waitcnt(clkfreq/10+cnt)

    pc.str(String("All Done"))
    pc.tx(13)
    

PUB testPin(outPin, inPin, mask) | out, state
{{
Tests a pin out of the set of prop pins. Can either test inverse (all pins high except pin) or standard
(set pin high, others low). Mask specifies which pins to ignore setting/checking. Expects dira to be set
Leaves outa in the test state after return
}}
    dira := (|< outPin)
    out := (|< outPin) & mask
    outa := out 
    state := ina[inPin]

    pc.dec( outPin )
    pc.tx(" ")
    pc.dec( state )
    pc.tx(" ")
    pc.str(String("...."))
    if state == 1
      pc.str(String("ok"))
    else
      pc.str(String("FAIL"))
    pc.tx(13)

    dira := 0
    outa := 0
      
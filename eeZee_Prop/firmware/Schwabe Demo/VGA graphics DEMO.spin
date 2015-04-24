CON
  _clkmode = xtal1 + pll16x
  _xinfreq = 5_000_000

  '512x384
  tiles = gr#tiles
OBJ
  gr    : "vga graphics ASM"

PUB MainLoop|h,i,deg,x,y,mask,ii,char
    gr.start
    gr.pointcolor(1)
    repeat i from 0 to tiles - 1                        'init tile colors to white on black
      'gr.color(i,$FF00)
      gr.color(i,$FF<<8+i)                              'init tile colors "Nice view" 
    gr.text(0,0,string("Parallax VGA text and graphics"))
    gr.SimpleNum(464,32,123,3)

    gr.box(30,50,80,100)                                'draw a box
    'or
    'gr.shape(55,75,71,71,4,gr.deg(45))                  'draw a box


    gr.boxfill(40,60,70,90)                             'draw a filled box

    repeat i from 3 to 15
      gr.shape(256,192,300,300,i,gr.deg(90))            'i = 3  triangle
                                                        'i = 4  square
                                                        'i = 5  pentagon
                                                        'i = 6  hexagon
                                                        'i = 7  heptagon
                                                        'i = 8  octagon
                                                        'i = 9  nonagon
                                                        'i = 10 decagon
                                                        'i = 11 hendecagon
                                                        'i = 12 didecqgon
                                                        'i = 13 tridecagon
                                                        'i = 14 tetradecagon
                                                        'i = 15 pentadecagon
    repeat
      repeat i from 0 to 359
        gr.pointcolor(1)
        gr.shape(256,192,145,145,3,gr.deg(i))
        gr.shape(256,192,70,70,4,gr.deg(359-i*2))
        gr.shape(256,192,30,30,5,gr.deg(i*3))
        repeat 4000                                                  
        gr.pointcolor(0)
        gr.shape(256,192,145,145,3,gr.deg(i))
        gr.shape(256,192,70,70,4,gr.deg(359-i*2))
        gr.shape(256,192,30,30,5,gr.deg(i*3))
    
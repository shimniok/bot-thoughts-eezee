.include	"tn13Adef.inc"

			rjmp main

; r16 transmit 'buffer'
; r17 bit counter

MSG:
.db "www.bot-thoughts.com"
.db "ATtiny13 serial demo"
.db "written in assembly,"
.db "134 bytes of code   "
.db 0

main:		sbi DDRB, 0x01 ; set PB0 as output

			; Startup delay
			ldi r22, 5
wait1:		rcall Delay
			dec r22
			brne wait1

			; normal write
			ldi r16, 0x1b
			rcall TXByte
			rcall Delay
			ldi r16, 0x11
			rcall TXByte
			rcall Delay
			ldi r16, 0x0d
			rcall TXByte
			rcall Delay

			; clear screen
			ldi r16, 0x1b
			rcall TXByte
			rcall Delay
			ldi r16, 0x0c
			rcall TXByte
			rcall Delay
			ldi r16, 0x0d
			rcall TXByte
			rcall Delay

			; Point Z at the beginning of the message
start:		ldi	zh, byte2(MSG<<1)
			ldi	zl, byte1(MSG<<1)	

			; Loop through the message and send bytes until
			; readching string termination '\0'
NextByte:	lpm r16, Z+
			tst r16			; if r16 == '\0'
			breq start		; start over again
			rcall TXByte
			rcall Delay
			rjmp NextByte

; Transmit a byte via serial with 9600,8,N,1
;  r16 - byte to transmit
;
TXByte:		ldi r17, 9 ; put 9 in counter register
txloop:		cpi r17, 9 ; if r17 == 9 (first bit)
			breq Send0 ; send start bit (low)
			cpi r17, 0 ; if bitcnt == 0, send stop
			breq SendStop
			lsr r16 ; shift off the next bit, LSB first
			brcs Send1 ; if it is 1 (C=1) then send 1
Send0:		cbi PORTB, 0x01 ; send a 0=low
			rjmp BitDone
Send1:		sbi PORTB, 0x01 ; send a 1=high
			rjmp BitDone
SendStop:	sbi PORTB, 0x01 ; send stop bit, 1=high
			ret
BitDone:	dec r17

; delaying 999 cycles:
			ldi  R19, 0x03
WGLOOP4:	ldi  R20, 0x65 ; 65 4.8077kHz;  6E 4.4khz, 5E 5.1kHz
WGLOOP5:	dec  R20
			brne WGLOOP5
			dec  R19
			brne WGLOOP4
; delaying 1 cycle:
			nop

			rjmp txloop ; else do the next bit

; Delay 120,000 cycles
;
Delay:
          	ldi  R19, 0x0a
WGLOOP0:  	ldi  R20, 0xC6
WGLOOP1:  	ldi  R21, 0xC9
WGLOOP2:  	dec  R21
          	brne WGLOOP2
          	dec  R20
          	brne WGLOOP1
          	dec  R19
          	brne WGLOOP0
          	ldi  R19, 0x3C
WGLOOP3:  	dec  R19
          	brne WGLOOP3
			ret

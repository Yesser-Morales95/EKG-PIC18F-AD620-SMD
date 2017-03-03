#include <18F4550.h>
#device adc=10
#use delay(clock=48M) 
#fuses  HSPLL,  NOWDT,  NOBROWNOUT,  NOPROTECT,  NOLVP,  NODEBUG,  USBDIV,  PLL5, CPUDIV1, VREGEN, MCLR, NOPBADEN, WRTB, CPB,NOCPD,NOPUT
#build(reset=0x000800,interrupt=0x000808:0x000818) 
#ORG 0x0000,0x07ff {}
#use rs232(baud=9600,BITS =8,PARITY=N, xmit=PIN_C6, rcv=PIN_C7)
//!#use I2C(MASTER,sda=PIN_B0,scl=PIN_B1,force_hw) 

//!// CONSTANTES UTILIZADAS PARA LA EEPROM AT24C1024B
//!#define EE_dev_addr 0xA0
//!#define EE_P0_0 0x00
//!#define EE_P0_1 0x02
//!
//!/*****************FUNCION GLOBAL PARA  ESCRITURA DE EEPROM*********************/
//!void I2C_snd_char(unsigned short ee_p0 ,unsigned short addr1 ,unsigned short addr2 ,unsigned short send_data) {
//!                i2c_start();
//!                I2C_write(EE_dev_addr|ee_p0);
//!                I2C_write(addr2);
//!                I2C_write(addr1);
//!                I2C_write(send_data);
//!                I2C_stop();
//!                delay_ms(10);
//!}
//!
//!/*******************FUNCION GLOBAL PARA LECTURA DE EEPROM**********************/
//!BYTE I2C_rcv_char(unsigned short ee_p0 ,unsigned short addr1 ,unsigned short addr2) {
//!                BYTE c;
//!                I2C_start();
//!                I2C_write(EE_dev_addr | ee_p0);
//!                I2C_write(addr2);
//!                I2C_write(addr1);
//!                I2C_start();
//!                I2C_write(EE_dev_addr | ee_p0 | 0x01);
//!                c = I2C_read(0);
//!                I2C_stop();
//!                return c;
//!}


void main(void)
   {
   int16 val,valR;
   int datoTX[2];
   int datoTX2[2];
   char c;
   int adress;
   // SETUP REGISTROS
   setup_comparator(NC_NC_NC_NC);   //Los comparadores Analogicos estaran apagados.
   setup_adc_ports(AN0_to_AN2|VSS_VDD);   //AN0 sera analogica las demas Digitales.
   SETUP_ADC(ADC_CLOCK_INTERNAL);   //La fuente de reloj para la conversion sera
 
  inicio: 
  adress=0;
       do {
     c=getc();
     delay_us(100);
          } while(c!='1' && c!='2' && c!='3');

       switch (c)
                 {
                  case '1':      //Lectura en tiempo real 
                      {
                      SET_ADC_CHANNEL(0);      //Lectura canal AN0.
                      val=read_adc();
                      datoTX[0]=val >> 8;     //Asignacion de desplazamiento hacia la derecha                                            
                      datoTX[1]=val & 0xFF;   //Asignacion AND de Bits  
                      delay_us(100);          //Tiempo de Muestreo Se�al
                      putc(datoTX[0]);           
                      putc(datoTX[1]);        //Envio de Datos
                      delay_us(5);
                      output_low(PIN_C0);
                     
                      goto inicio;
                      } //end case 1
                                            
                  case '2': //Guardar datos
                      {              
                    for (adress=0; adress<=255;adress++)
                        {     
                         SET_ADC_CHANNEL(0);       //Lectura canal AN0.
                         val=read_adc();
                         delay_ms(5);
                         write_eeprom(adress,val);
                         delay_ms(5);
                         // write_eeprom(adress+20,datoTX[1]);   
                             if (adress==254 ){ 
                        output_high(PIN_C0); 
                        delay_ms(700); }
                         c=getc();
                         delay_us(50);
                       if (adress==255 && c!='2')  
                          {goto inicio;}
                       
                        } //end for
//!                       second:
//!                       c=getc();
//!                       if (adress==128 && c!='2') {goto inicio;}
//!                       else {goto second;}
//!
//!                goto second;

                     goto inicio;
                       }//end case 2
                           
                  case '3': //Mostrar datos
                       {               
                     for (adress=0; adress<=255;adress++)
                         {     
                          valR= read_eeprom(adress);
                          // datoTX2[1]= read_eeprom(adress+20);
                          datoTX2[0]=valR >> 8;     //Asignacion de desplazamiento hacia la derecha                                            
                          datoTX2[1]=valR & 0xFF; //Asignacion AND de Bits  
                          putc(datoTX2[0]);
                          putc(datoTX2[1]);
                          delay_us(5);
                           if (adress==254 ){ 
                        output_high(PIN_C0); 
                        delay_ms(700); }
                          output_low(PIN_C0);
                          c=getc();
                          delay_us(50);
                           if (adress==255 && c!='3')  
                           {goto inicio;}
                         } //end for
                          goto inicio;
                        }//end case 3
               }//end switch
}//end void
   
   
   
                                   

  

# VHDL projects

In Programmable logic devices class, each project cover some aspects of project, simulation and synthesis necessary to develop basic knowledge about VHDL.

[VHDL reference](https://www.csee.umbc.edu/portal/help/VHDL/summary.html)

Lessons:

- [Process](https://youtu.be/sWHDGBHgyhA)
- [Syncronous process and FSM](https://youtu.be/RXuawXrZLYM)
- [Synthesis and Quartus](https://youtu.be/HI98txnuVAc)
- [Subprograms in VHDL](https://youtu.be/5CFANS8QrRY)
- [Custom types in VHDL](https://youtu.be/dDV4duRsP-M)
- [External files usage VHDL](https://youtu.be/GcfW6t3I1vw)
- [IP components](https://youtu.be/lNM48rQQpDQ)
- [SoftCore Nios](https://youtu.be/v6_9k6YIsrw)
- [SoftCore RISCV](https://youtu.be/iPl8RegzXcY)


The softwares used for those projects are:
- [Sigasi](https://www.sigasi.com/) - Text editor with intelisense for VHDL
- [Modelsim](https://www.intel.com.br/content/www/br/pt/software/programmable/quartus-prime/model-sim.html) - VHDL project simulator
- [Quartus](https://www.intel.com/content/www/us/en/programmable/downloads/download-center.html) - Synthesis tool

In modelsim terminal
```
Choose the project diretory and execute
*do tb.do*

to terminate the simulation
*quit -sim*
```

## *Blue blocks*:

- [x] [Adder](https://i.imgur.com/kV1Iqj9.png) 16 bits (adder):
- [x] [Mux](https://i.imgur.com/5Jbjskc.png) 4 bits (mux4)
- [x] [Shifter](https://i.imgur.com/y5jxKyT.png) 8 bits to 16 bits shift left (shifter)
- [x] [Seven segments display](https://i.imgur.com/YJcmlo5.png) (seven_segment_cntrl)
- [x] [Register](https://i.imgur.com/vlFe3u5.png) 16 bits (reg16)
- [x] [Counter](https://i.imgur.com/dKwcNAN.png) 2 bits (Counter)
- [x] [Mult](https://i.imgur.com/m0bScT9.png) 4 bits (mult44)
- [x] Implement and [FSM](https://i.imgur.com/WKB50rC.png)
- [x] Implement [8x8 multiplier](https://i.imgur.com/rjuPvcI.png)

## *Procedures and Functions*:

Do a package containing a ```function``` and a ```procedure``` described as follow:

- [x] Function

A function that implements an **arithmetic SHIFT left** operation for a **STD_LOGIC_VECTOR** signal. 

Two arguments must be passed to your function: 
- *data*
- *n*

The first is the vector that will be rotated and the second how many bits will be rotated. Make a generic function, that is, it should work for any vector size.

- Must be a **generic function** for any vector size
- Your function must be implemented in a package.
- You **cannot use** the numerical package change / rotation function. 

Tip: use only concatenation. Also write a testbench to test the package and function.

- [x] Procedure

A procedure that receives 8 signed signals and returns the **average**, the **highest** value and the **lowest** value of these 8 numbers.

As follow, respectively, names of those returns:
- *ave*
- *max* 
- *min*

*Your procedure must be implemented in a package. 

Also write a testbench to test the package and the procedure.

## *Circular queue*

Based on the example of Register Bench:

- [x] Create a FIFO ```circular queue``` based in 32 16-bit registers.

Entries, exits, entity name and behavior are up to you as long as they correspond to the logical behavior of a circular queue and FIFO order.

## *Digital filter*

- [x] Design an entity that implements a ***digital moving average filter*** according the equation and diagram bellow

![this](https://i.imgur.com/dFyGtJx.png)

Requirements:
- 32 coeficients
- Use of 32 words of 16 bit from SRAM memory
- The code must infer SRAM IPs

Tip: The filter is syncronous (have clk and rst)

## *FSM animation*


The component must be like shown bellow

![](https://i.imgur.com/WiU1qIA.png)

- [x] Design of a *FSM* that animates a seven segments display. The entity contains two entries: 
- *clk*
- *stop*
and an output 
- *dout*  (7 bits)

The *dout* output is the **diplay input**. 
Use **clock frequency** as **1kHz**. 

The animation should cause a clockwise movement, to create a smooth movement, you must activate 2 states at same time for a shorter period. The sequence of segments is: 
***a - ab - b - bc - c - cd - d - de - e - ef - f - fa***

If the input *stop* is activated to High, the circuit must return 'a' state, keeping it until *stop* gets in the low state.

## *Softcore*

### FIltro digital de média móvel

Este projeto implementa um filtro digital de média móvel como um dos periférico do núcleo riscv. O periférico implementa 32 registradores de 32 bits dispostos em um array, onde a escrita do array é feita de forma circular. Há 3 formas de acessar o periférico, pelos registradores de controle, entrada ou saída. O periférico implementa duas funções, reset e adicionar novo dado onde reset reseta todos os registradores e novo dado adiciona o valor do registrador de entrada no array de registradores. É possível a leitura da média do array de registradores através da leitura do registrador de saída.

A ideia principal desse periférico é receber dados de forma contínua e retornar a média movél desses dados a partir dos ultimos 32 dados.

#### Funcionamento do periférico

O periférico é conectado ao barramento de dados e funciona baseado em 2 maquinas de estado, uma de controle geral e uma de controle de entrada de novos dados.

![](https://i.imgur.com/MdRtKwi.png)

Na maquina de controle geral há 4 estados, sendo RESET e NEW_DATA comandos para o periférico. WAIT_DATA é o estado em que fica o periférico enquanto o mesmo faz os procedimentos necessários antes de poder voltar para IDLE.

Para o procedimento de reset (RESET) não foi necessária a implementação em uma outra máquina de estados, pois nesse procedimento é ligado o clear do banco de registradores, limpando a informação por eles armazenada. A entrada nesse procedimento se da pela escrita do valor alto no bit 0 do registrador de control (DIG_FILT_CTRL).

![](https://i.imgur.com/4rN0ffA.png)

No procedimento de novo dado (NEW_DATA) há a aquisição do conteúdo escrito no registrador de entrada (DIG_FILT_IN), dps o cálculo da saída que é armazenada no registrador de saída (DIG_FILT_OUT) e a atualização do index do banco de registradores. Esse processo é controlado por uma maquina de estados exclusiva desse procedimento.

![](https://i.imgur.com/W2UFhaA.png)

Há também um bit que sinaliza se o periférico está livre ou não (data_is_ready), sendo ele o bit 31 do registrador de controle, esse bit fica em estado alto durante o estado IDLE de controle, caso esse estado mude, o bit é colocado em estado lógico baixo, sinalizando que o periférico está ocupado. Assim que o periférico deixa de estar ocupado o bit volta ao estado alto.

A seguir os sinais de debug do registrador, sendo esses dispensáveis para o funcionamento do periférico.
![](https://i.imgur.com/eU2JKEm.png) ![](https://i.imgur.com/SRRYexH.png)

Na implementação realizada, o sexto display está conectado a um registrador externo (OUTBUS), utilizado para verificar o procedimento de leitura do registrador de saida (DIG_FILT_OUT).

##### Processos de entrada e saída

O processo a seguir é responsável por detectar uma requisição de leitura do periférico e de acordo com os filtros retorna para barramento de dados a informação requisitada.
![](https://i.imgur.com/19b1icZ.png)

O processo a seguir é responsável pelo tratamento da requisição de escrita no periférico, ainda nesse mesmo processo há o tratamento das maquinas de estado descritas anteriormente.
![](https://i.imgur.com/6C2DeAf.png)

#### Código em C

Em hardware.h as definição dos endereços utilizados:
```c 
#define PERIPH_BASE		((uint32_t)0x4000000) 

#define DIG_FILT_CTRL   (*(_IO32 *) (PERIPH_BASE + 80))
#define DIG_FILT_IN     (*(_IO32 *) (PERIPH_BASE + 84))
#define DIG_FILT_OUT    (*(_IO32 *) (PERIPH_BASE + 88))	
```
NOTA: os endereços supracitados são referentes as words x"14", x"15" e x"16" utilizados para leitura e escrita no .vhd

O protótipo das funções e definições: 
```c 
#define RESET_REGS 	0x00000001
#define NEW_DATA 	0x00000002

void dig_filt_reset();
void dig_filt_add_data(uint32_t data_in);

uint32_t dig_filt_get_output();
uint32_t dig_filt_data_is_ready();
```

Implementação das funções:
```c 
/* Retorna o bit 31 do registrador de controle */
uint32_t dig_filt_data_is_ready(){
	return (DIG_FILT_CTRL >> 31)&(1);
}

/* Escreve o comando de reset do registradores 
   no registrador de controle em seguida 
   espera a liberação do periférico */
void dig_filt_reset(){
	DIG_FILT_CTRL = RESET_REGS;
	while(!dig_filt_data_is_ready());
}

/* Escreve data_in no registrador de entrada, 
   envia o comando de adicionar novo dado
   e aguarda liberação do periférico */
void dig_filt_add_data(uint32_t data_in){
	DIG_FILT_IN = data_in;
	DIG_FILT_CTRL = NEW_DATA;
	while(!dig_filt_data_is_ready());
}

/* Retorna o valor do registrador de saída */
uint32_t dig_filt_get_output(){
	return DIG_FILT_OUT;	
}
```

O código a seguir é um exemplo para observar-se o funcionamento do periférico:

```c
#include "dig_filt.h"

int main(){
	uint8_t i = 0;

	dig_filt_reset();						// reset function

	while (1){

		dig_filt_add_data(0xA);				// add new data function
		OUTBUS = dig_filt_get_output();		// get output function
		delay_(10000);

		i++;
		if (i == 40)
		{
			i = 0;
			dig_filt_reset();				// reset function
		}
	}

	return 0;
}

```


[.](https://i.imgur.com/LrbW3hj.png)

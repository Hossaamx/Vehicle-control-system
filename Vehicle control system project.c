/*
 ============================================================================
 Name        : Vehicle.c
 Author      : Hossam Hassan
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include"header.h"
#define ON 1
#define OFF 0
int Engine, AC,engine_controller_state=OFF;
int room_temp= 20; int engine_temp=90;
int speed=100;
//if we don't want to display the engine functions make it 0
#define check 1
int main(void) {

	//scanf("%d", &check);
	display_options_1();


	/*if(ret==0){
		return 0;
	}

	if(Engine == ON){
		sensors_set_menu();
	}
	if(Engine== OFF){
		display_options_1();
	}*/



}
void tempConv(int* temp){
	*temp= (*temp*5/4)+1 ;

}
/*the function take an input to choose a state while the engine is on if it is turned of it will
  move back to the display options function*/
void sensors_set_menu(void){
	char c;
	printf("a. Turn off the engine\n");
	printf("b. Set the traffic light colour.\n");
	printf("c. Set the room temperature (Temperature sensor).\n");
#if check
	printf("d. Set the engine temperature (Engine Temperature Sensor).\n");
#endif
	fflush(stdout);
	scanf(" %c",&c);
	switch(c){
	case 'a':
		Engine=OFF;
		display_options_1();
		break;
	case 'b':
		 speed=trafic_light_to_speed();
		break;
	case 'c':
		AC=room_temperature(&room_temp);
		break;

	case 'd':
		engine_controller_state= engine_temp_data(&engine_temp);
		break;
	}
	if(speed== 30){
		AC= ON;
		engine_controller_state=ON;
		//room_temp=room_temp*(5/4)+1;
		//engine_temp = engine_temp*(5/4)+1;
		tempConv(&room_temp);
		tempConv(&engine_temp);

	}
	if(c=='b'|| c=='c'|| c=='d'){
		display();

	}
	/*As long as the engine is on we must display then take a new input*/
	if(Engine ==ON){
		sensors_set_menu();
	}
	else{
		display_options_1();
	}
}
/*this is the main function that will call all the other functions y itself and will take the first input */
int display_options_1(void){
	char c;
	printf("a. Turn on the vehicle engine\n");
	printf("b. Turn off the vehicle engine\n");
	printf("c. Quit the system\n");
	fflush(stdout);
	scanf(" %c",&c);
		switch(c){
		case 'a':
			Engine =ON;
			printf("a. Turn on the vehicle engine\n\n");
			sensors_set_menu();
			return 1;
			break;
		case 'b':
			printf("b. Turn off the vehicle engine\n\n");
			display_options_1();
			return 2;
			break;
		case 'c':
			printf("c. Quit the system\n\n");
			exit(0);
		default:
			return 0;
		}
}
void Engine_State(int i){
	if(i== ON){
		printf("Engine is ON\n");
	}
	else{
		printf("Engine is OFF\n");
	}
}
void Engine_controller_State(int i){
	if(i== ON){
		printf("Engine temperature controller state is ON\n");
	}
	else{
		printf("Engine temperature controller state is OFF\n");
	}
}
void AC_State(int i){
	if(i== ON){
		printf("AC is ON\n");
	}
	else{
		printf("AC is OFF\n");
	}
}
int trafic_light_to_speed(void){
	printf("Enter the current traffic light color\n");
			fflush(stdout);
	char c;
	scanf(" %c",&c);
	if(c == 'g'|| c=='G'){
		return 100;
	}
	else if(c == 'o'|| c=='O'){
		return 30;
	}
	else if(c == 'r'|| c=='R'){
		return 0;
	}
	else{
		return 0;
	}
}
int engine_temp_data(int *engine_temp){
	printf("Enter the engine temperature\n");
	fflush(stdout);
	scanf("%d", *&engine_temp);
	if(*engine_temp < 100 || *engine_temp> 150){
		*engine_temp= 125;
		return ON;

	}
	else{
		return OFF;
	}
}
int room_temperature(int *room_temp){
	printf("Enter the room temperature\n");
	fflush(stdout);
	scanf("%d", *&room_temp);
	if(*room_temp < 10 || *room_temp> 30){
			*room_temp= 20;
			return ON;

		}
		else{
			return OFF;
		}
}
void display(void){
	Engine_State(Engine);
	AC_State(AC);
	printf("The vehicle speed is %d Km/Hr \n", speed);
	printf("Room temperature is %d degree\n", room_temp);
#if check
	Engine_controller_State(engine_controller_state);
	printf("Engine temperature is %d degree \n\n\n",engine_temp);
#endif
}



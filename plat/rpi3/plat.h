
#include <main.h>
void plat_init(mailbox_functions_t *mbox_func){
	mbox_func->set_power_state_on = bcm2837_set_power_state_on;
	mbox_func->get_clock_rate = bcm2837_get_clock_rate;
	mbox_func->get_mac_address = bcm2837_get_mac_address;
}
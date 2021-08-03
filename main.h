
#include <platsupport/plat/mailbox_util.h>
typedef struct mailbox_functions_s{
	bool (*set_power_state_on)(mailbox_t *mbox, uint32_t device_id);
	int (*get_clock_rate)(mailbox_t *mbox, uint32_t clock_id);
	bool (*get_mac_address)(mailbox_t *mbox, uint8_t buffer[6]);
}
mailbox_functions_t;

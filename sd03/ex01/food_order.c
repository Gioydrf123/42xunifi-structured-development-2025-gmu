#include <unistd.h>

int check_resteurant_status(struct OrderRequest *request);
struct OrderConfirmation *create_standard_confirmation(void);
struct OrderConfirmation *create_preorder_confirmation(void);
void send_confirmation_notification(struct OrderConfirmation *confirmation);

int process_food_order(struct OrderRequest *request)
{
	int check = int check_resteurant_status(&request);
	if (check < 1)
		return 0;
	struct OrderConfirmation *confirmation = NULL;
	if (request->is_preorder)
		confirmation = create_preorder_confirmation();
	else
		confirmation = create_standard_confirmation();
	if (!confirmation)
		return 0;
	order_confirmation = send_confirmation_notification(&confirmation);
	return ;
}

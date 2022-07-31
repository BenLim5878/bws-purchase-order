#pragma once

namespace View {
	class PurchaseOrderView {
	public:
        void show(bool isValidInput = true);
		void processInput(int option);
	};
}
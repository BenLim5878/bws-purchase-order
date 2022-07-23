#pragma once

namespace View {
	class UpdatePurchaseOrderView {
	public:
		void show(int poID,bool isInputValid = true, bool isCompleted = false);
	};
}
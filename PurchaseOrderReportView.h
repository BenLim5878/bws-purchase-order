#pragma once
#include "PurchaseOrderRepository.h"

struct ReportConfig {
public:
	PurchaseOrderPriority purchaseOrderPriority;
	PurchaseOrderArrangement purchaseOrderArrangement;
	ReportPeriod reportPeriod;
};

namespace View {
	class PurchaseOrderReportView
	{
	private:
		void showCriteriaMenu();
		void showReportSelectionMenu();
	private:
		ReportConfig reportConfig;
	public:
		void show();
		void processInput(char selection);
	public:
		PurchaseOrderReportView(ReportConfig reportConfig);
		~PurchaseOrderReportView();
	};
}



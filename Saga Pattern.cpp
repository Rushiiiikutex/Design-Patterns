#include <iostream>
using namespace std;

class PaymentService {
public:
    bool deductAmount() {
        cout << "Amount deducted.\n";
        return true;
    }
    void refundAmount() {
        cout << "Amount refunded.\n";
    }
};

class BookingService {
public:
    bool reserveRoom() {
        cout << "Room reserved.\n";
        return true;
    }
    void cancelReservation() {
        cout << "Reservation cancelled.\n";
    }
};

int main() {
    PaymentService payment;
    BookingService booking;

    if (payment.deductAmount()) {
        if (!booking.reserveRoom()) {
            payment.refundAmount();  // Compensation
        }
    }
    return 0;
}

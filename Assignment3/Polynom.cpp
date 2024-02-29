#include <iostream>
#include <stdexcept>
using namespace std;

class Node {
public:
    int coefficient;
    int exponent;
    Node* next;

    Node(int coeff, int exp) : coefficient(coeff), exponent(exp), next(nullptr) {}
};

class Polynomial {
private:
    Node* head;

public:
    Polynomial() : head(nullptr) {}

    ~Polynomial() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insertTerm(int coeff, int exp) {
        Node* newNode = new Node(coeff, exp);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    void display() const {
        if (!head) {
            cout << "Polynomial is empty" << endl;
            return;
        }
        Node* temp = head;
        cout << "Polynomial expression: ";
        while (temp) {
            cout << temp->coefficient << "x^" << temp->exponent;
            temp = temp->next;
            if (temp)
                cout << " + ";
        }
        cout << endl;
    }

    Polynomial addPolynomials(const Polynomial& poly2) const {
        Polynomial result;
        Node* p1 = head;
        Node* p2 = poly2.head;

        while (p1 && p2) {
            if (p1->exponent > p2->exponent) {
                result.insertTerm(p1->coefficient, p1->exponent);
                p1 = p1->next;
            } else if (p1->exponent < p2->exponent) {
                result.insertTerm(p2->coefficient, p2->exponent);
                p2 = p2->next;
            } else {
                int sum = p1->coefficient + p2->coefficient;
                result.insertTerm(sum, p1->exponent);
                p1 = p1->next;
                p2 = p2->next;
            }
        }

        while (p1) {
            result.insertTerm(p1->coefficient, p1->exponent);
            p1 = p1->next;
        }
        while (p2) {
            result.insertTerm(p2->coefficient, p2->exponent);
            p2 = p2->next;
        }

        return result;
    }
};

int main() {
    Polynomial poly1, poly2;
    int coeff, exp, termCount;

    cout << "Enter the number of terms in Polynomial 1: ";
    cin >> termCount;
    cout << "Enter the terms for Polynomial 1 (coefficient exponent):" << endl;
    for (int i = 0; i < termCount; ++i) {
        cin >> coeff >> exp;
        poly1.insertTerm(coeff, exp);
    }

    cout << "Enter the number of terms in Polynomial 2: ";
    cin >> termCount;
    cout << "Enter the terms for Polynomial 2 (coefficient exponent):" << endl;
    for (int i = 0; i < termCount; ++i) {
        cin >> coeff >> exp;
        poly2.insertTerm(coeff, exp);
    }

    cout << "\nPolynomials entered:" << endl;
    poly1.display();
    poly2.display();

    Polynomial result = poly1.addPolynomials(poly2);

    cout << "\nResult of adding the two polynomials:" << endl;
    result.display();

    return 0;
}

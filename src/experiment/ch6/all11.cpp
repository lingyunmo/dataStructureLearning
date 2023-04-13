#include<iostream>

using namespace std;

typedef struct PolyNode {
    int coef;
    int exp;
    struct PolyNode *next;
} *Polynomial;

Polynomial read(Polynomial P);

void print(Polynomial P);

Polynomial getAdd(Polynomial P1, Polynomial P2);

Polynomial read(Polynomial P) {
    Polynomial s = NULL, temp;
    P = (struct PolyNode *) malloc(sizeof(struct PolyNode));
    temp = P;
    int n, COEF, EXP;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> COEF >> EXP;
        if (COEF != 0) {
            s = (struct PolyNode *) malloc(sizeof(struct PolyNode));
            s->coef = COEF;
            s->exp = EXP;
            P->next = s;
            P = s;
        }
    }
    P->next = NULL;
    return temp;
}

void print(Polynomial P) {
    int num = 0, temp = 0;
    Polynomial val = P;
    while (val->next) {
        val = val->next;
        temp++;
    }
    if (P->next != NULL) {
        while (P->next) {
            if (P->next->coef != 0) {
                cout << P->next->coef << " " << P->next->exp;
                Polynomial val = P->next;
                while (val->next && val->next->coef == 0) {
                    val = val->next;
                }
                if (val->next == NULL)
                    cout << endl;
                else
                    cout << " ";
            } else
                num++;
            P = P->next;
        }
        if (num == temp)
            cout << 0 << " " << 0 << endl;
    } else
        cout << 0 << " " << 0 << endl;
}

Polynomial getAdd(Polynomial P1, Polynomial P2) {
    Polynomial P, temp = NULL, s = NULL;
    P = (struct PolyNode *) malloc(sizeof(struct PolyNode));
    temp = P;

    while (P1->next && P2->next) {
        if (P1->next->exp > P2->next->exp) {
            s = (struct PolyNode *) malloc(sizeof(struct PolyNode));
            s->coef = P1->next->coef;
            s->exp = P1->next->exp;
            P->next = s;
            P = s;
            P1 = P1->next;
        } else if (P1->next->exp < P2->next->exp) {
            s = (struct PolyNode *) malloc(sizeof(struct PolyNode));
            s->coef = P2->next->coef;
            s->exp = P2->next->exp;
            P->next = s;
            P = s;
            P2 = P2->next;
        } else {
            s = (struct PolyNode *) malloc(sizeof(struct PolyNode));
            s->coef = P2->next->coef + P1->next->coef;
            s->exp = P2->next->exp;
            P->next = s;
            P = s;
            P1 = P1->next;
            P2 = P2->next;
        }
    }
    if (P1->next)
        P->next = P1->next;
    else
        P->next = P2->next;
    return temp;
}

int main() {
    Polynomial P1 = NULL;
    Polynomial P2 = NULL;
    Polynomial P = NULL;
    P1 = read(P1);
    P2 = read(P2);
    P = getAdd(P1, P2);
    print(P);
    return 0;
}

#define ElementType int
typedef struct LNode *PtrToLNode;

struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

int Length(List L) {
    Position p = L;
    int cnt = 0;
    while (p) {
        p = p->Next;
        cnt++;
    }
    return cnt;
}
int main(){

}
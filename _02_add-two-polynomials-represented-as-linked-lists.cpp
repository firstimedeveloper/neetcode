/**
 * Definition for polynomial singly-linked list.
 * struct PolyNode {
 *     int coefficient, power;
 *     PolyNode *next;
 *     PolyNode(): coefficient(0), power(0), next(nullptr) {};
 *     PolyNode(int x, int y): coefficient(x), power(y), next(nullptr) {};
 *     PolyNode(int x, int y, PolyNode* next): coefficient(x), power(y), next(next) {};
 * };
 */

class Solution {
public:
    PolyNode* addPoly(PolyNode* poly1, PolyNode* poly2) {
        PolyNode *ret = new PolyNode;
        PolyNode *cur = ret;
        while (true) {
        
            if (poly1 && poly2) {
                if (poly1->power > poly2->power) {
                    cur->next = new PolyNode(poly1->coefficient, poly1->power);
                    poly1 = poly1->next;
                } else if (poly1->power < poly2->power) {
                    cur->next = new PolyNode(poly2->coefficient, poly2->power);
                    poly2 = poly2->next;
                } else {
                    int tmp = poly1->coefficient + poly2->coefficient;
                    if (tmp != 0) {
                        cur->next = new PolyNode(tmp , poly1->power);
                        poly1 = poly1->next;
                        poly2 = poly2->next;
                    } else {
                        poly1 = poly1->next;
                        poly2 = poly2->next;
                        continue ;  
                    }
                
                }
            } else if (poly1 && !poly2) {
                cur->next = poly1;
                break ;
            } else if (poly2 && !poly1) {
                cur->next = poly2;
                break ;
            } else break ;
            cur = cur->next;
        }
        return ret->next;
        
    }
};

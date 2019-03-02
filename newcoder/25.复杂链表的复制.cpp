class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if (pHead == nullptr) return nullptr;
        map<RandomListNode*, RandomListNode*> o2n;
        
        RandomListNode* nHead = new RandomListNode(pHead->label);
        o2n.insert(make_pair(pHead, nHead));
        
        RandomListNode *ocur = pHead->next, *nprv = nHead, *ncur;
        while (ocur) {
            ncur = new RandomListNode(ocur->label);
            nprv->next = ncur;
            o2n.insert(make_pair(ocur, ncur));
            
            ocur = ocur->next;
            nprv = ncur;
        }
        
        ocur = pHead;
        ncur = nHead;
        while (ocur) {
            if (ocur->random != nullptr) {
                auto iter = o2n.find(ocur->random);
                ncur->random = iter->second;
            }
            
            ocur = ocur->next;
            ncur = ncur->next;
        }
        
        return nHead;
    }
};

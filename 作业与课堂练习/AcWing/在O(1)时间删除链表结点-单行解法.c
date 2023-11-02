void deleteNode(struct ListNode* node) {
    *node=*(node->next);
}

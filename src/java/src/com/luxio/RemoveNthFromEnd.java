package com.luxio;

import javax.swing.*;
import java.util.ArrayList;
import java.util.List;

public class RemoveNthFromEnd {
    public static void main(String[] args) {

    }

    public static ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode dummy = new ListNode(0, head);
        ListNode first = head;
        ListNode second = dummy;
        for (int i = 0; i < n; i++) {
            first = first.next;
        }
        while (first != null) {
            first = first.next;
            second = second.next;
        }

        second.next = second.next.next;
        return dummy.next;
    }

    public static void print(ListNode head) {
        ListNode cur = head;
        while (cur.next != null) {
            System.out.println(cur.val);
            cur = cur.next;
        }
    }
}

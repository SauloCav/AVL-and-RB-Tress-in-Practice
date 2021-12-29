# AVL-and-RB-Tress-in-Practice

<strong>A scenario for order management of an online purchasing department using AVL and Red-Black trees</strong>

<strong>Activity proposal:</strong></br>
During this period of pandemic, a large store in Crateús expanded its offer to consumers and opened its first virtual store. To manage the orders received, the company needs a solution to manage some information.</br>
<strong>Users:</strong> It is known that users of the online portal have: cpf, full name, address and bank details (credit card). The system, in order to validate any inconsistency received from the online portal, validates the registered CPFs, as it uses this information as an identifying key for each user's registration information.</br>
<strong>Orders:</strong> Each user will have an order arrangement (reference of the store's large order arrangement), whose stored information is: identification number, item description, quantity, value, customer identifier and status (cancelled, delivered, completed , processing). Seeking to maintain system uniformity, each order must have a unique key that identifies it.</br>
<strong>Operations:</strong> Observing the day-to-day of the requests received, it can be seen that users make few changes to their registration, however, requests are frequently updated: either in the change of status, or in the quantity of item of an order whose statuses is still open (in process). When using the application by store employees, it is possible to verify the entire arrangement of orders already made and registered users.</br>
Knowing about such characteristics and needs, develop the construction of a solution with proper use of tree structures AVL e RB.

# philosophers42
In this project, you will learn the basics of threading a process. You will see how to create threads and you will discover mutexes.

Ce projet est une introduction au threading et aux processus, et sur comment travailler
sur le même espace mémoire.
Vous apprendrez à manipuler des threads.
Vous découvrirez les mutex, les sémaphores et la mémoire partagée.

<h1 style="color:blue;" >Classic Problem of Synchronization</h1> (The Dining-Philosophers Problem)

The Dining Philosopher Problem states that K philosophers seated around a circular table with one chopstick between each pair of philosophers. There is one chopstick between each philosopher. A philosopher may eat if he can pick up the two chopsticks adjacent to him. One chopstick may be picked up by any one of its adjacent followers but not both. 

<h2>Philosopher either</h2>

<h3>Thinks<h3>

When a philosopher thinks, he does not interact with his colleagues

<h3>Eats</h3>

When a philosopher gets hungry he tries to pick up the two forks that are closest to him (left & right). A philosopher may pick up only one fork at a time.
One cannot pick up a fork that is alreaddy in the hand of a neighbour.
When a hungry philosopher has both his forks at the same time, he eats without releasing his forks. When he has finished eating, he puts down both of his forks and starts thinking again.

# TestQPropertyThreading
Toy project to determine how to best access Q_PROPERTY from qml in a different thread

Branch master contains the code used in Stack Overflow question https://stackoverflow.com/questions/62659809/best-practice-accessing-q-property-in-qml-from-another-thread

Branch threadsafe uses a model so the QML can interface with a seperate controller thread safely (as far as I understand).

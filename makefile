Driver.class: Driver.java
	javac Driver.java

run: Driver.class
	java Driver 

clean:
	rm calculator/*.class
	rm *.class
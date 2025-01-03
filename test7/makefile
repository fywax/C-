OBJ = Time.o Timing.o Event.o Professor.o Group.o Classroom.o schedulable.o Exception.o TimeException.o TimingException.o XmlFileSerializerException.o Test7.o
TARGET = Test7

# exec
$(TARGET): $(OBJ)
	g++ -o $(TARGET) $(OBJ)

# fichiers objets
%.o: %.cpp %.h
	g++ -c $< -o $@

# Pour Test7.o car pas de h 
$(TARGET).o: $(TARGET).cpp
	g++ -c $(TARGET).cpp -o $(TARGET).o

# Nettoyage
clean:
	rm -f $(OBJ) $(TARGET) core

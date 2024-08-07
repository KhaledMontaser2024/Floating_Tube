import scienceplots
import sys
import matplotlib 
matplotlib.use('Qt5Agg')
matplotlib.style.use(['science', 'notebook', 'grid'])
from PyQt5 import QtCore, QtWidgets

from matplotlib.backends.backend_qt5agg import FigureCanvasQTAgg
from matplotlib.figure import Figure
import rospy
from float_task.msg import floatMsg
from std_msgs.msg import UInt16
tationCommand=UInt16()
rospy.init_node("Station_Node")
Commandpub = rospy.Publisher("/station_to_float",UInt16,queue_size=10)

class MplCanvas(FigureCanvasQTAgg):

    def __init__(self, parent=None, width=5, height=4, dpi=100):
        fig = Figure(figsize=(width, height), dpi=dpi)
        self.axes = fig.add_subplot(111)
        super(MplCanvas, self).__init__(fig)


class MainWindow(QtWidgets.QMainWindow):

    def __init__(self, *args, **kwargs):
        super(MainWindow, self).__init__(*args, **kwargs)
        self.axis1 = None
        self.axis2 = None
        self.selected_axis = None
        # Create the maptlotlib FigureCanvas object,
        # which defines a single set of axes as self.axes.
        self.sc = MplCanvas(self, width=5, height=4, dpi=100)
        self.button1 = QtWidgets.QPushButton("1")
        self.button2 = QtWidgets.QPushButton("2")
        self.button1.clicked.connect(lambda: Commandpub.publish(1))
        self.button2.clicked.connect(self.send)

        # Create a QVBoxLayout
        layout = QtWidgets.QVBoxLayout()

        # Add the button to the layout
        layout.addWidget(self.sc)
        layout.addWidget(self.button1)
        layout.addWidget(self.button2)

        # Create a QWidget and set the layout to it
        widget = QtWidgets.QWidget()
        widget.setLayout(layout)

        # Set the QWidget as the central widget of the QMainWindow
        self.setCentralWidget(widget)


        # Add the QWidget containing the button to the layout of the QMainWindow
        # self.setLayout(layout)

        self.show()
        StationSubscriber = rospy.Subscriber ("/float_to_station",floatMsg,self.ReadingsHandler)

    
    def send(self):  
        self.selected_axis = 2
        Commandpub.publish(self.selected_axis)
        

    def ReadingsHandler(self, msg):
        print(msg.readings)
        #print(msg.readings[:16])
        #print(msg.readings[16:])        
        # if self.selected_axis == 2:
        #     self.axis2 = msg.readings[:16]
        #     self.selected_axis = 3
        #     Commandpub.publish(self.selected_axis)

        # elif self.selected_axis == 3:
        #     self.axis1 = msg.readings[:16]
        #     self.selected_axis = None
        #     self.plot()

    def plot(self):
        if self.axis1 is not None and self.axis2 is not None:
            self.sc.axes.clear()
            self.sc.axes.plot(self.axis1,self.axis2)
            self.sc.axes.relim()
            self.sc.draw()

app = QtWidgets.QApplication(sys.argv)
w = MainWindow()
app.exec_()
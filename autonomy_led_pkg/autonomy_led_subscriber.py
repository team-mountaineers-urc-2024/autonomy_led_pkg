import rclpy
from rclpy.node import Node
import serial
from std_msgs.msg import String


class AutonomyLEDSubscriber(Node):

    def __init__(self):
        super().__init__('autonomy_led_subscriber')

        self.declare_parameter('topic_parameter', '/led_color_topic')
        self.declare_parameter('autonomous_parameter', 'autonomous')
        self.declare_parameter('teleop_parameter', 'teleop')
        self.declare_parameter('arrival_parameter', 'arrival')

        self.subscription = self.create_subscription(
            String,
            self.get_parameter('topic_parameter').get_parameter_value().string_value,
            self.listener_callback,
            10)
        self.subscription  # prevent unused variable warning

    def listener_callback(self, str_msg):
        data = ""
        if str_msg.data.lower() == self.get_parameter('autonomous_parameter').get_parameter_value().string_value:
            data = "0"
        elif str_msg.data.lower() == self.get_parameter('teleop_parameter').get_parameter_value().string_value:
            data = "1"
        elif str_msg.data.lower() == self.get_parameter('arrival_parameter').get_parameter_value().string_value:
            data = "2"
        elif str_msg.data.lower() == "weewoo":
            data = "3"
        elif str_msg.data.lower() == "party":
            data = "4"
        elif str_msg.data.lower() == "wvu":
            data = "5"
        elif str_msg.data.lower() == "rainbow":
            data = "6"
        elif str_msg.data.lower() == "monash":
            data = "7"
        else:
            self.get_logger().error(f'Provided data "{str_msg.data}" was not valid for any of three modes')
            return
        data = bytes(data, 'utf-8')
        port = "/dev/ttyACM0"
        ser = serial.Serial(port, 9600)
        ser.write(data)
        ser.close()




def main(args=None):
    rclpy.init(args=args)

    autonomy_led_subscriber = AutonomyLEDSubscriber()

    rclpy.spin(autonomy_led_subscriber)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    autonomy_led_subscriber.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
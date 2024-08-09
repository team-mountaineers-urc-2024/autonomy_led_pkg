# autonomy_led_pkg

## Description
This package controls the rover's LEDs during the Autonomous Navigation mission. 
The package includes an Arduino script that should be flashed onto an Arduino
Leonardo connected internally to a LattePanda Sigma. Additionally it includes a
subscription node that serially writes to the Leonardo, and can turn on LEDs to
Red, Blue and Green. The node is looking for 'autonomous', 'teleop, or 'arrival'
at the topic 'autonomy_led_topic' to switch the LEDs to Red, Blue, and Green
respectively. These modes and the topic are parameterized and can be changed
from a launch file.

extends GDExample

@onready var timer: Timer = $"../Timer"
 # Called when the node enters the scene tree for the first time.
func _ready() -> void:	
	pass
	

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta: float) -> void:
	if timer.time_left == 0 :
		eat("apple") #测试方法
		timer.start(1)
		print(health)
		print(timer.time_left)	

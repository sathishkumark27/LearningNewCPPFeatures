# Write a program to calculate the resources needed 
# to remodel a golf course hole.  
#     See assignment description for details.
# 
# The inputs should be:
#     Enter Course Length: 
#     Enter Course Width: 
# 
# The outputs should be:
#     Total square yards of rough sod:
#     Total square yards of smooth sod:
#     Tons of sand:
#     Number of retaining wall bricks:
#     Number of bushes:
#     Total Mowing Time (mins):

import math
from math import pi

def calculate_smooth_sod(width):
    radius= width / 4
    smooth_sod_area= round(2 * pi * radius * radius)
    return smooth_sod_area

def calculate_sand_area(width):
    radius= width / 6
    sand_trap_area= round(pi * radius * radius)
    return sand_trap_area;

def calculate_sand_tons(width):
    width_in_ft= width * 3
    sand_trap_radius= width_in_ft / 6
    sand_trap_area= pi * sand_trap_radius * sand_trap_radius
    total_sand= round((sand_trap_area * 100)/2000)
    return total_sand

def calculate_amount_of_bricks(width):
    length_of_wall= pi *(width * 3 / 6)
    amount_of_bricks= round(length_of_wall*3)
    return amount_of_bricks

def calculate_amount_of_bushes(length, width):
    perimeter= 2 * (length + width)
    amount_of_bushes= round(perimeter - 2)
    return amount_of_bushes

def calculate_rough_sod(length, width,smooth_sod_area, sand_trap_area):
    area= length * width
    rough_sod_area= round(area-smooth_sod_area-sand_trap_area)
    return rough_sod_area

def calculate_time_to_mow(rough_sod_area, smooth_sod_area):
    total_mow_time= round((rough_sod_area * 0.5) + (smooth_sod_area + 1))
    return total_mow_time

def display(rough_sod_area, smooth_sod_area, total_sand, amount_of_bricks, amount_of_bushes, total_mow_time):
    print("Total square yards of rough sod: ",rough_sod_area)
    print("Total square yards of smooth sod: ",smooth_sod_area)
    print("Tons of sand: ",total_sand)
    print("Number of retaining wall bricks: ",amount_of_bricks)
    print("Number of bushes: ",amount_of_bushes)
    print("Total mowing time (mins): ",(total_mow_time/60))

def call():
    length= float(input("Enter Course Lenght: "))
    width= float(input("Enter Course Width: "))
    smooth_sod_area= calculate_smooth_sod(width)
    sand_trap_area= calculate_sand_area(width)
    rough_sod_area= calculate_rough_sod(length, width, smooth_sod_area, sand_trap_area)
    amount_of_bricks= calculate_amount_of_bricks(width)
    total_sand= calculate_sand_tons(width)
    amount_of_bushes= calculate_amount_of_bushes(length, width)
    total_mow_time= calculate_time_to_mow(rough_sod_area, smooth_sod_area)
    display(rough_sod_area, smooth_sod_area, total_sand, amount_of_bricks, amount_of_bushes, total_mow_time)
    
call()                       



   
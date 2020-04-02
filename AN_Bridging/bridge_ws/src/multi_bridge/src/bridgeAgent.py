#! /usr/bin/env python

import numpy as np 
import torch
import torch.nn as nn
import math 
from network import Network
import rospy
from std_msgs.msg import String, Int8
from geometry_msgs.msg import Vector3
from agent import Agent
from customAgent import CustomAgent 
from MADDPGAgent import MADDPGAgent 
from centralQ import CentralQ

GAMMA = .9

algs = {
    1: "CUST_MADDPG_OPT",
    2: "MADDPG",
    3: "CENTRAL_Q", #REMINDER: if choosing 3, make sure to only run the bridgeAgent.py in the launch file
}
ALGORITHM = 3
description = algs[ALGORITHM]
rospy.init_node('Dummy', anonymous = True)

if description == "CUST_MADDPG_OPT":
    actPars = {'state_n': 11, 
                'in_n': 11,
                'own_n': 7,
                'output_n': 2,
                'prob': True,
                'hidden': 100,
                'depth': 2,
                'activation': nn.ReLU(),
                'preprocess': False,
                'postprocess': True,
                'epochs': 1,
                'loss_fnc': "policy_gradient",
                'sigma': 1,
                'dropout': .20}
    valuePars = {'prob': False,
                'sigma': 1, #relative 
                'state_n': 11,
                'in_n': 11,
                'output_n': 1,
                'hidden': 100,
                'depth': 2,
                'activation': nn.ReLU(),
                'preprocess': False,
                'postprocess': True,
                'epochs': 1,
                'loss_fnc': "MSE",
                'dropout': .20 }             
    actorTrainPars = {'alpha1': 2,
                'alpha2': 2,
                'lambda': .5,
                'horizon': 16,
                'buffer': 1000,
                'explore': 1, #variance of gaussian noise
                'lr': .0000001,
                'gamma': GAMMA
                }
    valueTrainPars = {
                'batch': 16,
                'lr': .0000001,
                'gamma': GAMMA }
    ROSparams = {'stateSub': "/bridger" ,
                    'subQueue': 1,
                    'actionPub': "/bridgerSubscribe",
                    'pubQueue': 1,
                    'delta_t': .05,
                    'numAgents': 2}
    params = {"actorParams": actPars, "valueParams": valuePars, "actorTrain": actorTrainPars, "valueTrain": valueTrainPars, "ROS": ROSparams}
    bridger = CustomAgent(params)
if description == "MADDPG":
    actPars = {'state_n': 11, 
                'own_n': 7,
                'in_n': 11,
                'output_n': 2,
                'prob': False,
                'hidden': 100,
                'depth': 2,
                'activation': nn.ReLU(),
                'preprocess': False,
                'postprocess': True,
                'epochs': 1,
                'loss_fnc': "policy_gradient",
                'sigma': 1,
                'dropout': .10}
    valuePars = {'prob': False,
                'sigma': 1, #relative 
                'state_n': 11,
                'output_n': 1,
                'in_n': 13,
                'hidden': 100,
                'depth': 2,
                'activation': nn.ReLU(),
                'preprocess': False,
                'postprocess': True,
                'epochs': 1,
                'loss_fnc': "MSE",
                'dropout': .10 }             
    actorTrainPars = {'alpha1': 2,
                'alpha2': 2,
                'lambda': .5,
                'horizon': 16,
                'buffer': 1000,
                'explore': .9, 
                'lr': .0000001,
                'gamma': GAMMA
                }
    valueTrainPars = {
                'batch': 16,
                'lr': .0000001,
                'gamma': GAMMA }
    ROSparams = {'stateSub': "/bridger" ,
                            'subQueue': 1,
                            'actionPub': "/bridgerSubscribe",
                            'pubQueue': 1,
                            'delta_t': .05,
                            'numAgents': 2}
    params = {"actorParams": actPars, "valueParams": valuePars, "actorTrain": actorTrainPars, "valueTrain": valueTrainPars, "ROS": ROSparams}
    bridger = MADDPGAgent(params)
if description == "CENTRAL_Q":
    valuePars = {'prob': False,
                'sigma': 1, #relative 
                'trainMode': True,
                'state_n': 11,
                'output_n': 84, #-2,0,2 for each 4 legs plus 3 actions where corresponds: stop and unhook, stop and hook front, stop and hook back
                'in_n': 11,
                'hidden': 100,
                'depth': 2,
                'activation': nn.ReLU(),
                'preprocess': False,
                'postprocess': True,
                'epochs': 1,
                'loss_fnc': "MSE",
                'dropout': .10 }             
    valueTrainPars = {
                'batch': 16,
                'lr': .000001,
                'gamma': GAMMA,
                'alpha1': 1.5,
                'alpha2': 6,
                'alpha3': .1,
                'lambda': 1,
                'buffer': 1000,
                'explore': .9, }
    ROSparams = {'stateSub': "/bridger" ,
                'subQueue': 1,
                'actionPub': "/bridgerSubscribe",
                'pubQueue': 1,
                'tankPub': "tankerSubscribe",
                'delta_t': .05,
                'numAgents': 2}
    params = { "valueParams": valuePars, "valueTrain": valueTrainPars, "ROS": ROSparams}
    bridger = CentralQ(params)

while(True):
    x = 1+1
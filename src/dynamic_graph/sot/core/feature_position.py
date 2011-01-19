# -*- coding: utf-8 -*-
# Copyright 2011, Florent Lamiraux, Thomas Moulard, JRL, CNRS/AIST
#
# This file is part of dynamic-graph.
# dynamic-graph is free software: you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public License
# as published by the Free Software Foundation, either version 3 of
# the License, or (at your option) any later version.
#
# dynamic-graph is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# General Lesser Public License for more details.  You should have
# received a copy of the GNU Lesser General Public License along with
# dynamic-graph. If not, see <http://www.gnu.org/licenses/>.

from dynamic_graph.sot.core import FeaturePoint6d
from dynamic_graph import plug

class FeaturePosition (object):
    """
    Position of a rigid-body in space as a feature

      Input:
        a string: name of the feature,
        a signal<MatrixHomo>: defining the value of the feature,
        a signal<Matrix>: defining the jacobian of the feature with respect
                          to the robot configuration,
        an homogeneous matrix: defining the reference value of the feature.

      Members containing a signal:
        position:  position input signal (MatrixHomo),
        reference: reference position input signal (MatrixHomo),
        Jq:        Jacobian input signal (Matrix),
        select:    selection flag "RzRyRxTzTyTx" (string).
        """
    def __init__(self, name, signalPosition=None, signalJacobian = None,
                 referencePosition = None):
        self.name = name
        self.feature = FeaturePoint6d(self.name)
        self.reference = FeaturePoint6d(self.name + '.ref')
        if referencePosition:
            self.reference.signal('position').value = tuple(referencePosition)
        if signalPosition:
            plug(signalPosition, self.feature.signal('position'))
        if signalJacobian:
            plug(signalJacobian, self.feature.signal('Jq'))
        self.feature.signal('sdes').value = self.reference
        self.feature.signal('selec').value = '111111'
        self.feature.frame('current')

        # Signals stored in members
        self.position = self.feature.signal('position')
        self.reference = self.reference.signal('position')
        self.Jq = self.feature.signal('Jq')
        self.error = self.feature.signal('error')
        self.select = self.feature.signal('selec')

from graphviz import Digraph

dot = Digraph()
dot.attr('node', shape='rect')

dot.node('A', 'Statements\n\nCompound\nAssignment\nIf Then\nIf Then Else\nWhile\nWith\nUse\nProcedure\nFunction')
dot.node('B', 'Expression\n\nArithmetic\nBoolean\nString')
dot.node('C', 'Declaration\n\nCompound\nSimple\nAssignment')
dot.node('D', 'Package\n\nSimple\nCompound')
dot.node('E', 'Bool Expression\n\nDelimited\nOp\nOp2')
dot.node('F', 'Arithmetic Expression\n\nID\nInt\nFloat\nBoolean\nDelimited\nOp')

dot.edges(['AA', 'AB', 'AD', 'AC', 'BF', 'BE', 'CC', 'CB', 'DD', 'EE', 'EF', 'FF'])
dot.render('flowchart', format='png', cleanup=True)
#!/usr/bin/python
# --------------------------------------------------------
# -- Bullet librairy
# --------------------------------------------------------
import lutinModule as module
import lutinTools as tools


def get_desc():
	return "AGG C++ graphic drawer"



def create(target):
	myModule = module.Module(__file__, 'agg', 'LIBRARY')
	
	myModule.add_module_depend(['etk', 'freetype'])
	
	myModule.add_path(tools.get_current_path(__file__)+"/agg/")
	myModule.add_path(tools.get_current_path(__file__)+"/agg/util/")
	
	myModule.add_export_path(tools.get_current_path(__file__))
	
	myModule.add_src_file([
		'agg/agg_arc.cpp',
		'agg/agg_arrowhead.cpp',
		'agg/agg_bezier_arc.cpp',
		'agg/agg_bspline.cpp',
		'agg/agg_curves.cpp',
		'agg/agg_embedded_raster_fonts.cpp',
		'agg/agg_font_freetype.cpp',
		'agg/agg_gsv_text.cpp',
		'agg/agg_image_filters.cpp',
		'agg/agg_line_aa_basics.cpp',
		'agg/agg_line_profile_aa.cpp',
		'agg/agg_rounded_rect.cpp',
		'agg/agg_sqrt_tables.cpp',
		'agg/agg_trans_affine.cpp',
		'agg/agg_trans_double_path.cpp',
		'agg/agg_trans_single_path.cpp',
		'agg/agg_trans_warp_magnifier.cpp',
		'agg/agg_vcgen_bspline.cpp',
		'agg/agg_vcgen_contour.cpp',
		'agg/agg_vcgen_dash.cpp',
		'agg/agg_vcgen_markers_term.cpp',
		'agg/agg_vcgen_smooth_poly1.cpp',
		'agg/agg_vcgen_stroke.cpp',
		'agg/agg_vpgen_clip_polygon.cpp',
		'agg/agg_vpgen_clip_polyline.cpp',
		'agg/agg_vpgen_segmentator.cpp'])
	
	#ewol abstraction of the graphic librairies :
	myModule.add_src_file([
		'draw/debug.cpp',
		'draw/Color.cpp',
		'draw/Image.cpp'])
	
	# add the currrent module at the 
	return myModule

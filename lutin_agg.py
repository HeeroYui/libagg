#!/usr/bin/python
# --------------------------------------------------------
# -- Bullet librairy
# --------------------------------------------------------
import lutin.module as module
import lutin.tools as tools


def get_desc():
	return "AGG C++ graphic drawer"



def create(target):
	my_module = module.Module(__file__, 'agg', 'LIBRARY')
	
	my_module.add_module_depend(['etk', 'freetype'])
	
	my_module.add_path(tools.get_current_path(__file__)+"/agg/")
	my_module.add_path(tools.get_current_path(__file__)+"/agg/util/")
	
	my_module.add_export_path(tools.get_current_path(__file__))
	
	my_module.add_src_file([
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
		'agg/agg_vpgen_segmentator.cpp'
		])
	my_module.add_header_file([
		'agg/agg_arc.h',
		'agg/agg_array.h',
		'agg/agg_arrowhead.h',
		'agg/agg_bezier_arc.h',
		'agg/agg_bspline.h',
		'agg/agg_curves.h',
		'agg/agg_embedded_raster_fonts.h',
		'agg/agg_font_freetype.h',
		'agg/agg_gsv_text.h',
		'agg/agg_image_filters.h',
		'agg/agg_line_aa_basics.h',
		'agg/agg_rounded_rect.h',
		'agg/agg_trans_affine.h',
		'agg/agg_trans_double_path.h',
		'agg/agg_trans_single_path.h',
		'agg/agg_trans_warp_magnifier.h',
		'agg/agg_vcgen_bspline.h',
		'agg/agg_vcgen_contour.h',
		'agg/agg_vcgen_dash.h',
		'agg/agg_vcgen_markers_term.h',
		'agg/agg_vcgen_smooth_poly1.h',
		'agg/agg_vcgen_stroke.h',
		'agg/agg_vpgen_clip_polygon.h',
		'agg/agg_vpgen_clip_polyline.h',
		'agg/agg_vpgen_segmentator.h'
		])
	#ewol abstraction of the graphic librairies :
	# TODO : Maybe deprecated ...
	my_module.add_src_file([
		'draw/debug.cpp',
		'draw/Color.cpp',
		'draw/Image.cpp'
		])
	my_module.add_header_file([
		'draw/Color.h',
		'draw/Image.h'
		])
	return my_module
